#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
from pathlib import Path
from textwrap import dedent


# ───────────────────────────────── MENU PRINCIPAL
class Menu:
    class Ops:
        MP = "Make_package"
        MF = "Make_file"
        Q  = "Quitter"

    m = {
        Ops.MP: "Créer / gérer les packages",
        Ops.MF: "Créer une classe C++ (.cpp / .hpp)",
        Ops.Q : "Quitter le programme",
    }

    @staticmethod
    def choose() -> str:
        print("\n=== MENU PRINCIPAL ===")
        for i, (k, desc) in enumerate(Menu.m.items(), 1):
            print(f"{i} - {desc}")
        while True:
            choix = input("Votre choix : ").strip()
            if choix.isdigit() and 1 <= int(choix) <= len(Menu.m):
                return list(Menu.m.keys())[int(choix) - 1]
            print("Entrée invalide, recommencez.")


# ───────────────────────────────── GESTION DES PACKAGES
class PackageManager:
    base_dir = Path.cwd()

    class Choix:
        model      = "model"
        entity     = "entity"     # ← ajouté
        service    = "service"
        controller = "controller"
        view       = "view"
        utils      = "utils"
        COURANT    = "."          # dossier courant
        Q          = "Quitter"

    m = {
        Choix.model:      "Package  model",
        Choix.entity:     "Package  entity",
        Choix.service:    "Package  service",
        Choix.controller: "Package  controller",
        Choix.view:       "Package  view",
        Choix.utils:      "Package  utils",
        Choix.COURANT:    "Dossier courant",
        Choix.Q:          "Retour menu précédent",
    }

    @staticmethod
    def lister_existants():
        print("\n--- Packages existants ---")
        présents = [
            nom for nom in PackageManager.m.keys()
            if nom not in {PackageManager.Choix.Q, PackageManager.Choix.COURANT}
            and (PackageManager.base_dir / nom).is_dir()
        ]
        print(" ".join(f"[✓] {p}" for p in présents) if présents else "(aucun)")

    @staticmethod
    def choisir_package() -> Path | None:
        while True:
            PackageManager.lister_existants()
            print("\n--- Choisissez un package ---")
            for i, (k, desc) in enumerate(PackageManager.m.items(), 1):
                print(f"{i} - {desc}")
            choix = input("Votre choix : ").strip()
            if choix.isdigit() and 1 <= int(choix) <= len(PackageManager.m):
                cle = list(PackageManager.m.keys())[int(choix) - 1]
                if cle == PackageManager.Choix.Q:
                    return None
                if cle == PackageManager.Choix.COURANT:
                    return PackageManager.base_dir
                dossier = PackageManager.base_dir / cle
                dossier.mkdir(exist_ok=True)
                return dossier
            print("Entrée invalide.")


# ───────────────────────────────── CRÉATION DES FICHIERS
class FileMaker:
    @staticmethod
    def snake_to_macro(name: str) -> str:
        return name.upper() + "_HPP"

    @staticmethod
    def creer_fichiers():
        # 1) nom simple
        while True:
            classe = input("Nom de la classe (sans extension) : ").strip()
            if classe:
                break

        # 2) choix (package ou courant)
        dossier = PackageManager.choisir_package()
        if dossier is None:                     # retour arrière
            return

        # 3) suffixe : seulement si package ≠ {model, entity, courant}
        specials = {
            PackageManager.base_dir.name,       # courant
            PackageManager.Choix.model,
            PackageManager.Choix.entity,
        }
        need_suffix = dossier.name not in specials
        suffixe     = dossier.name.capitalize() if need_suffix else ""

        base_name   = f"{classe}{suffixe}" if need_suffix else classe
        cpp_path    = dossier / f"{base_name}.cpp"
        hpp_path    = dossier / f"{base_name}.hpp"

        for p in (cpp_path, hpp_path):
            if p.exists():
                print(f"[!] {p.relative_to(Path.cwd())} existe déjà → annulé.")
                return

        guard = FileMaker.snake_to_macro(base_name)
        hpp_content = dedent(f"""\
            #pragma once
            // {base_name}.hpp  --  généré automatiquement

            class {base_name} {{
            public:
                {base_name}();
                ~{base_name}();
            }};
            """)
        cpp_content = dedent(f"""\
            #include "{base_name}.hpp"

            {base_name}::{base_name}() {{}}

            {base_name}::~{base_name}() {{}}
            """)

        hpp_path.write_text(hpp_content)
        cpp_path.write_text(cpp_content)

        rel_cpp = cpp_path.relative_to(Path.cwd())
        rel_hpp = hpp_path.relative_to(Path.cwd())
        print(f"[✓] Fichiers créés : {rel_cpp}  et  {rel_hpp}")


# ───────────────────────────────── BOUCLE PRINCIPALE
if __name__ == "__main__":
    while True:
        op = Menu.choose()

        if op == Menu.Ops.Q:
            print("Au revoir !")
            break
        if op == Menu.Ops.MP:
            PackageManager.choisir_package()
        elif op == Menu.Ops.MF:
            FileMaker.creer_fichiers()

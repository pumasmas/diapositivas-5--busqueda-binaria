#!/usr/bin/env python3

###############################################
## Preamble, do not edit please (unless bug)
###############################################
import glob
import os
import shutil
import subprocess
import sys

# Global variables to be filled-in through @target
TARGETS = {}
TARGET_DESCRIPTIONS = {}
# Subscribes a function to TARGETS and its description to TARGET_DESCRIPTIONS
def target(name : str, description : str):
    assert " " not in name, "Target names can't have whitespace"
    def wrapper(value):
        TARGETS[name] = value
        TARGET_DESCRIPTIONS[name] = description
        return value
    return wrapper

# Removes recursively in an OS agnostic manner
def rm_rf(to_remove : str|list[str]):
    if isinstance(to_remove, str):
        to_remove = [to_remove]
    print(f"Removing {'  '.join(to_remove)}", "\n")
    for remove_glob in to_remove:
        for path in glob.glob(remove_glob):
            path = os.path.expanduser(os.path.expandvars(path))
            try:
                if os.path.islink(path) or os.path.isfile(path):
                    os.remove(path)
                elif os.path.isdir(path):
                    shutil.rmtree(path, ignore_errors=True)
            except FileNotFoundError:
                pass

# Creates a path
def mkdir_p(path: str) -> None:
    os.makedirs(path, exist_ok=True)

# Copies a file or directory (recursively)
def cp(src: str, dst: str) -> None:
    if os.path.isdir(src):
        # If dst exists and is a directory, copy inside it
        if os.path.isdir(dst):
            dst = os.path.join(dst, os.path.basename(src))
        shutil.copytree(src, dst, dirs_exist_ok=True)  # recursive copy
    else:
        if os.path.isdir(dst):
            dst = os.path.join(dst, os.path.basename(src))
        shutil.copy2(src, dst)

# Moves a file or directory
def mv(src: str, dst: str) -> None:
    if os.path.isdir(dst):
        dst = os.path.join(dst, os.path.basename(src))
    shutil.move(src, dst)

# Executes a command
def run(command : str, args : list[str] = []):
    xs = [command] + args
    print(" ".join(xs),"\n")
    subprocess.run(xs, check=True)

# Current working directory
CWD = os.getcwd()






# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

###############################################
## Build configuration settings
###############################################

# What target to run when none is specified
DEFAULT_TARGET = "main"
# This file's description on the help dialogue
SCRIPT_DESCRIPTION = "Build script for Pu++ Slides"

# Main file name (without extension)
MAIN = "main"
# Compiler and flags
LATEXMK = "latexmk"
FLAGS = [
    "-pdf",
    "-shell-escape",
    "-interaction=nonstopmode",
    "-g"
]
# Docker image name
IMAGE_NAME = "pumasmas-latex-builder"
# Extra cleanup files
EXTRA_CLEANUP = [
    f"_minted-{MAIN}", "_minted",
    "sections/*.aux",
    "*.nav", "*.snm", "*.vrb", "*.run.xml", "*.bbl", "*.blg"
]

###############################################
## Target definitions
###############################################

@target("main", "Compile the document")
def target_main():
    run(LATEXMK, FLAGS + [f"{MAIN}.tex"])

@target("clean", "Remove build artifacts")
def target_clean():
    run(LATEXMK, ["-C"])
    rm_rf(EXTRA_CLEANUP)

@target("docker", "Compile the document using Docker")
def target_docker():
    run("docker", ["build", "-t", IMAGE_NAME, "."])
    run("docker", ["run", "--rm", "-v", f"{CWD}:/app:rw", IMAGE_NAME, sys.argv[0]])

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~






###############################################
## Postamble, do not edit please (unless bug)
###############################################

def main(argc, argv):
    assert DEFAULT_TARGET in TARGETS, f"The default target `{DEFAULT_TARGET}` was not found."
    # Identifies the target and runs it
    if argc == 1:
        TARGETS[DEFAULT_TARGET]()
    elif argc == 2 and argv[1] in TARGETS:
        TARGETS[argv[1]]()
    else:
        print(SCRIPT_DESCRIPTION)
        print("Usage:")
        max_len = max(len(t) for t in TARGETS)
        print(f"  {argv[0]} {' '*max_len}  {TARGET_DESCRIPTIONS[DEFAULT_TARGET]}")
        for t in TARGETS:
            if t == DEFAULT_TARGET:
                continue
            print(f"  {argv[0]} {t.ljust(max_len)}  {TARGET_DESCRIPTIONS[t]}")

if __name__ == "__main__":
    main(len(sys.argv), sys.argv)

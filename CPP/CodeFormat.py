# -*- coding: utf-8 -*-
"""
 Created by Monkey at 2020/10/7
"""
from pathlib import Path
import os

root = Path("./CPP")


def covert(path):
    files = os.listdir(path)
    for file in files:
        print(file)
        if os.path.isdir(path + file):
            covert(path + file + "/")
        if file.endswith(".cpp"):
            new_name = file.split(".")[0] + ".cc"
            os.rename(path + file, path + new_name)
        if file.endswith(".h"):
            new_name = file.split(".")[0] + ".hh"
            os.rename(path + file, path + new_name)


covert("./")

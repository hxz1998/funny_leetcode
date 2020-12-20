"""
  Created by Xiaozhong on 2018/11/8.
  Copyright (c) 2018/11/8 Xiaozhong. All rights reserved.

  简单的计算代码行数的小程序
"""

from pathlib import Path
import sys

path = Path(sys.argv[1])
file_type = sys.argv[2]


def fun_counter(dir_name, count):
    for item in dir_name.iterdir():
        print(item)
        if item.is_file() and item.match("*/*." + file_type):
            with item.open(encoding="utf-8") as file_obj:
                while file_obj.readline():
                    count = count + 1
        elif item.is_dir():
            count fun_counter(item, count)
    return count


print(fun_counter(path, 0))

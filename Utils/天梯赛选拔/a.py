import pandas as pd
import numpy as np
import re
import csv

from collections import defaultdict

data = {}

df = pd.read_csv("0.csv")

keys = df.iloc[:, 2]    # 所有行的第三列
values = df.iloc[:, 4]  # 所有行的第五列

for key, value in zip(keys, values):
    if key not in data:
        data[key] = [0] * 4
    data[key][0] = value

# for x in data.items():
#     print(x)

for T in range(1, 4):
    df = pd.read_csv(f"{T}.csv")
    keys = df.iloc[:, 1]
    values = df.iloc[:, 2]
    for key, value in zip(keys, values):
        print(key)
        matches = re.findall(r'\((.*)\)', key)
        if len(matches) == 0:
            continue
        key = matches[0]
        if key not in data:
            data[key] = [0] * 4
        data[key][T] = value

# for x in data.items():
#     print(x)

filename = f"merge(gbk).csv"
headers = ["姓名", "真题训练", "选拔赛1", "选拔赛2", "选拔赛3"]

with open(filename, "w", newline="", encoding="gbk") as f:
    writer = csv.writer(f)
    writer.writerow(headers)
    
    for key, values in data.items():
        row = [key] + values
        writer.writerow(row)
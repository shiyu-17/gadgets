import pandas as pd
import os

# 读取Excel表格
df = pd.read_excel(r'E:\Work\project\names.xlsx')

# 获取人名列的数值
names = df['name']

# 获取图像文件夹路径
image_folder = r'E:\Work\project\photos'

# 获取图像文件夹中的所有文件
image_files = os.listdir(image_folder)

# 遍历文件夹中的每个图像文件
for i, image_file in enumerate(image_files):
    # 获取当前人名
    name = names[i]

    # 构建新的文件名
    new_name = os.path.join(image_folder, f'{i}-{name}.jpg')

    # 重命名文件
    os.rename(os.path.join(image_folder, image_file), new_name)
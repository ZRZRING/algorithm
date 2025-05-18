import os
import re

def add_spaces_to_folders(directory='.'):
    """
    修改指定目录下所有文件夹名称，确保中文字符与数字或英文字母之间有空格。

    参数:
    directory (str): 目录路径，默认为当前目录。
    """
    # 遍历目录中的所有文件夹
    for folder_name in os.listdir(directory):
        old_folder_path = os.path.join(directory, folder_name)
        
        # 检查是否是文件夹
        if os.path.isdir(old_folder_path):
            # 使用正则表达式在中文字符和数字、字母之间插入空格
            new_folder_name = re.sub(r'([\u4e00-\u9fff])([a-zA-Z0-9])', r'\1 \2', folder_name)  # 中文字符与字母、数字间加空格
            new_folder_name = re.sub(r'([a-zA-Z0-9])([\u4e00-\u9fff])', r'\1 \2', new_folder_name)  # 字母、数字与中文字符间加空格
            
            # 更新文件夹名称
            if new_folder_name != folder_name:
                new_folder_path = os.path.join(directory, new_folder_name)
                os.rename(old_folder_path, new_folder_path)
                print(f"重命名: {old_folder_path} -> {new_folder_path}")

    print("重命名完成。")

# 示例用法
add_spaces_to_folders()

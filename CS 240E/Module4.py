# 创建一个字典
dictionary = {}

# 插入键值对
dictionary["name"] = "Alice"
dictionary["age"] = 25

# 查找键对应的值
print(dictionary["name"])  # 输出: Alice

# 更新键值对
dictionary["age"] = 26

# 删除键值对
del dictionary["name"]

# 检查字典是否为空
print(len(dictionary) == 0)  # 输出: False
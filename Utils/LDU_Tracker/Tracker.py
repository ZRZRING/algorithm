from selenium import webdriver

path = r'D:\Driver\chromedriver.exe'
driver = webdriver.Chrome(path)

driver.get("https://icpc.ldu.edu.cn/login")

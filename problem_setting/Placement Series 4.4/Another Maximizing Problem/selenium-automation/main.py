import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from keys import login, password
from selenium.webdriver.common.keys import Keys
driver = webdriver.Firefox()
driver.get("https://polygon.codeforces.com/login")
element_login = driver.find_element(By.XPATH,"/html/body/div[2]/div[3]/form/table/tbody/tr[1]/td[2]/input")
element_password = driver.find_element(By.XPATH,"/html/body/div[2]/div[3]/form/table/tbody/tr[2]/td[2]/input")
login_send = driver.find_element(By.XPATH,"/html/body/div[2]/div[3]/form/table/tbody/tr[4]/td[2]/div/input")
element_login.send_keys(login)
element_password.send_keys(password)
login_send.click()
problem = driver.find_element(By.XPATH,"/html/body/div[2]/table/tbody/tr/td[1]/table/tbody/tr[1]/td[8]/a[1]")
problem.click()
test = driver.find_element(By.XPATH,"/html/body/div[2]/div[2]/div[5]/div[2]/span[7]/a")
test.click()
preview = driver.find_element(By.XPATH,'//*[@id="preview-tests"]')
preview.click()
driver.refresh()
gg = driver.find_element(By.CLASS_NAME,"test-table")
ah = gg.find_elements(By.TAG_NAME,"a")
for index, download in enumerate(ah):
    while not download.is_displayed():
        continue

    download.send_keys(Keys.COMMAND + Keys.RETURN)
    driver.switch_to.window(driver.window_handles[1])

    var = (index//2)//10
    if var:
        ek_aur_var = str(index//2)
    else:
        ek_aur_var = "0" + str(index//2)
    if index >= 4:
        time.sleep(8)
    else:
        time.sleep(4)
    # while True:
    #     try:
    #         content = driver.find_element(By.TAG_NAME,"pre").text
    #         break
    #     except:
    #         continue
    content = driver.find_element(By.TAG_NAME, "pre").text

    if index & 1:
        open(f"test-cases/out{ek_aur_var}.txt", "w").write(content)
    else:
        open(f"test-cases/in{ek_aur_var}.txt", "w").write(content)
    driver.switch_to.window(driver.window_handles[0])

time.sleep(30)
driver.close()

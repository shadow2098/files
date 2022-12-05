import requests
import time

def get_response():

	res = requests.request(method="GET", url="http://127.0.0.1:6001")
	print(res.text)

start = time.time()
get_response()
finish = time.time()
print(start - finish)
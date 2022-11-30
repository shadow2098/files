import requests

def get_response():

	res = requests.request(method="GET", url="http://127.0.0.1:6001")
	print(res.text)


get_response()
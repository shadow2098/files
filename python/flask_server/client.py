import requests

def get_response():
'''
	with open("input.json") as fl:
		data = json.load(fl)
		x = requests.post("http://localhost:8027", json=data)
		print(x.json())
'''


	res = request.get("http://127.0.0.1:6001")
	print(res.json())
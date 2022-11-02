from flask import Flask
from flask import request
from flask import render_template
from flask import redirect
from flask import make_response
import requests

app = Flask(__name__)

@app.route("/", methods=["POST", "GET"])
def long_function():
	if request.method == "GET":
		return render_template("main.hmtl")

	else:

                start = time.time()
                time.sleep(4) 
                res = requests.get("https://api.covid19api.com/country/brazil")
                finish = time.time()
                print("Work time - ", str(finish - start))

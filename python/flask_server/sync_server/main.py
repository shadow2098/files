import time
from flask import Flask
from flask import request



app = Flask(__name__)

@app.route("/")
def main_fun():

    if request.method == "GET":
        time.sleep(15)
        return "Hello. Function started"
        
    return "Hello. Function started"

if __name__ == "__main__":
    app.run(port=6001)

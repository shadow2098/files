from flask import Flask

app = Flask(__name__)

@app.route("/")
def main_fun():
    return "Hello. Function started"

if __name__ == "__main__":
    app.run(port=6001)
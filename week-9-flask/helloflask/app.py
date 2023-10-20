from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    colors = ["red", "blue"]

    if request.method == "GET":
        return render_template("index.html")
    else:
        color = request.form.get("color")

        if color in colors:
            return render_template("color.html", color=color)

        else:
            return "Choose a valid color!"
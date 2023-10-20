from pyfiglet import Figlet
import sys
import random

figlet = Figlet()

if len(sys.argv) == 1:
    font = random.choice(figlet.getFonts())

elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    font = sys.argv[2]

else:
    sys.exit(1)

try:
    figlet.setFont(font=font)
    
except:
    print("Invalid font")
    sys.exit(1)

text = input("Input: ")

print("Output:")

print(figlet.renderText(text))
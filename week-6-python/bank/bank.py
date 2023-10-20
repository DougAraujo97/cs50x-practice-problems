# Get user input
greeting = input("Greeting: ")

# Capitalize and strip input of whitespace
greeting = greeting.strip().capitalize()

# Output the required dollar amount depending on the greeting
if greeting.startswith("Hello"):
    print("$0")

elif greeting.startswith("H"):
    print("$20")

else:
    print("$100")
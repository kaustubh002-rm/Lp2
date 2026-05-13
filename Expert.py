# Expert System for Help Desk Management
# Using Forward Chaining Algorithm

# Knowledge Base
rules = {

    "wifi not working": "Restart router and reconnect WiFi",

    "forgot password": "Reset password using forgot password option",

    "computer slow": "Clear temporary files and restart system",

    "printer not working": "Check printer cable and install drivers",

    "internet issue": "Check network connection",

    "system hanging": "Close unnecessary programs and restart computer",

    "keyboard not working": "Reconnect keyboard or replace batteries",

    "mouse not working": "Check mouse connection",

    "screen blank": "Check monitor power cable",

    "software not opening": "Reinstall the software",

}

# Forward Chaining Algorithm
def expert_system(problem):

    for fact in rules:

        if problem == fact:
            return rules[fact]

    return "No solution found"

# Main Program
while True:

    problem = input("Enter problem: ").lower()

    solution = expert_system(problem)

    print("Solution:", solution)

    choice = input("Do you want to continue? (yes/no): ").lower()

    if choice == "no":
        print("Thank You")
        break
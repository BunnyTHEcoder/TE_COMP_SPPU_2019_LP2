import random
import datetime
import webbrowser


# Define a dictionary of pre-defined responses
responses = {
    "What's your name?": "My name is Chatbot.",
    "How old are you?": "I don't have an age. I'm a machine.",
    "Where do you live?": "I live in the computer.",
    "What's your favorite color?": "I don't have a favorite color.",
    "What's your favorite food?": "I don't eat food. I'm a machine.",
    "Do you have any pets?": "No, I don't have any pets.",
    "What's your hobby?": "I don't have hobbies. I'm a chatbot.",
    "What's your job?": "My job is to chat with people.",
    "What's your favorite movie?": "I don't watch movies. I'm a machine.",
    "What's your favorite book?": "I don't read books. I'm a chatbot.",
    "Do you like sports?": "I don't have opinions about sports. I'm a machine.",
    "What's your favorite sport?": "I don't have a favorite sport. I'm a chatbot.",
    "What's your favorite music genre?": "I don't have preferences for music genres.",
    "Do you play any instruments?": "No, I don't play any instruments.",
    "What's your favorite holiday?": "I don't have a favorite holiday.",
    "What's your favorite place to visit?": "I don't travel. I'm a machine.",
    "What's your favorite animal?": "I don't have a favorite animal. I'm a chatbot.",
    "What's your favorite thing to do?": "I like chatting with people.",
    "Do you prefer tea or coffee?": "I don't drink beverages. I'm a machine.",
    "What's your favorite season?": "I don't have a favorite season. I'm a chatbot.",
}

# Define a function to handle the chatbot's responses
def chatbot_response(user_input):
    # Answer the current time if the user input contains "time"
    if "time" in user_input:
        current_time = datetime.datetime.now().strftime("%H:%M:%S")
        current_year = datetime.datetime.now().strftime("%Y")
        return f"The current time in India is {current_time} on {current_year}."
    if "open google" in user_input:
        webbrowser.open("https://www.google.com/")
        return "Opening Google..."
    if "open youtube" in user_input:
        webbrowser.open("https://www.youtube.com/")
        return "Opening youtube..."
    # Otherwise, check if the user input matches a pre-defined response
    for question, response in responses.items():
        if user_input.lower() == question.lower():
            return response
    # If no pre-defined response is found, generate a random response
    return random.choice(["Interesting!", "Tell me more.", "I see.", "That's cool.", "Really?"])

# Start the chatbot
print("Hello! I'm a chatbot. Ask me anything!")
while True:
    # Get the user's input
    user_input = input()
    # Check if the user wants to quit
    if user_input.lower() == "quit":
        break
    # Respond
    response = chatbot_response(user_input)
    print(response)

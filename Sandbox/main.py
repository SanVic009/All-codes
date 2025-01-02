# from pynput import keyboard

# def on_press(key):
#     try:
#         print(f"Key: {key.char}, KeyCode: {key.vk}")
#     except AttributeError:
#         print(f"Special Key: {key}")

# with keyboard.Listener(on_press=on_press) as listener:
# #     listener.join()

# import keyboard

# def log_event(event):
#     print(f"key: {event.name}, Scan Code: {event.scan_code}")

# keyboard.hook(log_event)
# keyboard.wait('esc')
print("Enter the value: ")
xx = float(input())


print(xx)
import psutil
from pynput import keyboard


def on_press(key):
    try:
        print(f"they pressed is {key}")
        if key == keyboard.Key.esc:
            print("Escape key pressed. Quitting......")
            return False
    except AttributeError:
        print(f"special key pressed is {key}")

def main():
    with keyboard.Listener(
        on_press=on_press
    ) as listner:
        listner.join()

if __name__== "__main__":
    main()
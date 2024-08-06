import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk, ImageFilter, ImageEnhance

class ImageProcessingTool:
    def __init__(self, root):
        self.root = root
        self.root.title("Image Processing Tool")

        self.image = None
        self.img_label = tk.Label(root)
        self.img_label.pack()

        # Buttons
        tk.Button(root, text="Load Image", command=self.load_image).pack(side=tk.LEFT)
        tk.Button(root, text="Save Image", command=self.save_image).pack(side=tk.LEFT)
        tk.Button(root, text="Grayscale", command=self.apply_grayscale).pack(side=tk.LEFT)
        tk.Button(root, text="Blur", command=self.apply_blur).pack(side=tk.LEFT)
        tk.Button(root, text="Sharpen", command=self.apply_sharpen).pack(side=tk.LEFT)
        tk.Button(root, text="Crop", command=self.crop_image).pack(side=tk.LEFT)
        tk.Button(root, text="Resize", command=self.resize_image).pack(side=tk.LEFT)

        # Sliders for brightness and contrast
        self.brightness_slider = tk.Scale(root, from_=0.5, to=2.0, resolution=0.1, orient=tk.HORIZONTAL, label="Brightness", command=self.adjust_brightness)
        self.brightness_slider.pack(side=tk.LEFT)

        self.contrast_slider = tk.Scale(root, from_=0.5, to=2.0, resolution=0.1, orient=tk.HORIZONTAL, label="Contrast", command=self.adjust_contrast)
        self.contrast_slider.pack(side=tk.LEFT)

    def load_image(self):
        file_path = filedialog.askopenfilename()
        if file_path:
            self.image = Image.open(file_path)
            self.display_image()

    def display_image(self):
        if self.image:
            img_display = ImageTk.PhotoImage(self.image)
            self.img_label.config(image=img_display)
            self.img_label.image = img_display

    def apply_grayscale(self):
        if self.image:
            self.image = self.image.convert("L")
            self.display_image()

    def apply_blur(self):
        if self.image:
            self.image = self.image.filter(ImageFilter.BLUR)
            self.display_image()

    def apply_sharpen(self):
        if self.image:
            self.image = self.image.filter(ImageFilter.SHARPEN)
            self.display_image()

    def adjust_brightness(self, value):
        if self.image:
            enhancer = ImageEnhance.Brightness(self.image)
            self.image = enhancer.enhance(float(value))
            self.display_image()

    def adjust_contrast(self, value):
        if self.image:
            enhancer = ImageEnhance.Contrast(self.image)
            self.image = enhancer.enhance(float(value))
            self.display_image()

    def crop_image(self):
        if self.image:
            width, height = self.image.size
            self.image = self.image.crop((width//4, height//4, width*3//4, height*3//4))
            self.display_image()

    def resize_image(self):
        if self.image:
            self.image = self.image.resize((200, 200))
            self.display_image()

    def save_image(self):
        if self.image:
            file_path = filedialog.asksaveasfilename(defaultextension=".png")
            if file_path:
                self.image.save(file_path)
                messagebox.showinfo("Image Processing Tool", "Image saved successfully!")

if __name__ == "__main__":
    root = tk.Tk()
    app = ImageProcessingTool(root)
    root.mainloop()

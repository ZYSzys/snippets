import numpy as np 
from PIL import Image

def reduce_size(img):
    im = img.resize((400, 400), Image.ANTIALIAS)
    # im.show()
    # im.save('rs.png')
    return im

def blend_two_images():
    img1 = Image.open("vue.png") # name of merged image1
    img1 = img1.convert('RGBA')

    img2 = Image.open( "wheel.png") # name of merged image2
    img2 = reduce_size(img2).convert('RGBA')
    #imgg = Image.open('rs.png')
    #imgg = imgg
    
    img = Image.blend(img1, img2, 0.25)
    img.show()
    img.save("result.png")

if __name__ == '__main__':
    blend_two_images()
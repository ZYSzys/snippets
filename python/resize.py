import numpy as np 
from PIL import Image

def reduce_size(img):
	im = img.resize((160, 60), Image.ANTIALIAS)
	# im.save('xxx.jpg')
	return np.array(im)

if __name__ == '__main__':
	img = Image.open('xxx.jpg')
	res = reduce_size(img)
	print(res)
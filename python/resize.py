import numpy as np 
from PIL import Image

def reduce_size(img):
	im = img.resize((320, 240), Image.ANTIALIAS)
	im.show()
	# im.save('q&a.jpg')
	return np.array(im)

if __name__ == '__main__':
	img = Image.open('q&a.jpeg')
	res = reduce_size(img)
	print(res)
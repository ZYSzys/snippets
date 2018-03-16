import numpy as np 
from PIL import Image

def reduce_size(img):
	im = img.resize((160, 60), Image.ANTIALIAS)
	return np.array(im)
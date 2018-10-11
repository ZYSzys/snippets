import numpy as np 
from PIL import Image

def reduce_size(img, idx, h):
	im = img.resize((640, int(h)), Image.ANTIALIAS)
	# im.show()
	im.save('zzz'+ idx + '.jpg')
	return np.array(im)

if __name__ == '__main__':
  idx = 1
  for i in range(1, 15):
    img = Image.open(str(i) + '.jpg')
    h = img.size[1] / (img.size[0]/640)
    res = reduce_size(img, str(i), h)
    print(res)
import io
from PIL import Image
from aip import AipOcr

def ocr_img(img):
	APP_ID = '10666835'
	API_KEY = 'VoGORxDpMPfj4aap0Xafi7dK'
	SECRET_KEY = 'vsiVNqGINCmOyC3nqaTqAvpv2UyYTE3l'

	client = AipOcr(APP_ID, API_KEY, SECRET_KEY)
	region_im = img

	img_byte_arr = io.BytesIO()
	region_im.save(img_byte_arr, format='PNG')
	image_data = img_byte_arr.getvalue()
	response = client.basicGeneral(image_data)
	words_result = response['words_result']
	texts = ''.join([x['words'] for x in words_result])
	#print(texts)
	return texts

if __name__ == '__main__':
	for i in range(10):
		txt = ocr_img(Image.open('train/%04d.jpg' % i))
		print(txt)
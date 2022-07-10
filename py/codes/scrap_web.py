import urllib2
import requests
from bs4 import BeautifulSoup
from requests.auth import HTTPProxyAuth

#ref
#https://medium.freecodecamp.org/how-to-scrape-websites-with-python-and-beautifulsoup-5946935d93fe
#https://www.pyimagesearch.com/2015/10/12/scraping-images-with-python-and-scrapy/
#dl ini : https://www.facebook.com/graphicartsornament/photos/a.315229445668896.1073742145.165663013958874/315231895668651/?type=3&theater

#site_page = 'https://www.facebook.com/pg/graphicartsornament/photos/?tab=album&album_id=315229445668896'
site_page = 'https://stackoverflow.com'

proxy = urllib2.ProxyHandler({})
opener = urllib2.build_opener(proxy)
urllib2.install_opener(opener)
page = urllib2.urlopen(site_page)

soup = BeautifulSoup(page, 'html.parser')

photos = soup.find('div', attrs={'class':'_2eec'})
print photos
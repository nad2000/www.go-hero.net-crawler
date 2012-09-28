#-------------------------------------------------------------------------------
# Name:     process.py
#
# Author:   Radomirs Cirskis
#
# Created:  2012-02-26
# Licence:  WTFPL
#-------------------------------------------------------------------------------
#!/usr/bin/env python

import os, sys, email, re, urllib2, urlparse
import json
import bs4
import codecs
import warnings
import traceback

#import os, sys, email, re, urllib2, urlparse
#import bs4
#import codecs
#import warnings
#from subprocess import Popen, PIPE
#import traceback

# Configuration:
from config import *


def extract_all( name=None, attrs={}, **kwargs):
    global soup
    for el in soup.find_all( name,attrs=attrs, **kwargs):
        el.extract()

def get_contestants():
    """
    Retrieves contestant data
    Returns a dictionary wiht contestants
    """
    start_pos = 1
    contestants = {}
    # URL with a placeholeder
    full_url = GET_SCOREBOARD_URL+"&start_pos={}"
    while True:
        # raw JSON imput:
        raw = json.load( urllib2.urlopen(full_url.format(start_pos) ))
        if raw.has_key('rows'):
            contestants.update( { r['n']: r for r in raw['rows'] } )
            start_pos += 20
        else:
            break
    return contestants


def process_source():
    """
    Python script that downloads all the files from a specified URL with the matching information on
    metat data page specified by an URL
    In addition, the script writes into a .csv the following columns that should match
    the downloaded name of the file : FileName, ContestantName, Country, Language, Year, Round, Rank,
    ProblemName, Size(large/small), Time(hr), Time(min), Time(sec)
    """

    contestants = get_contestants()
    soup = bs4.BeautifulSoup(urllib2.urlopen(SOURCE_URL))

    for link in soup.find(id='content').find_all(title=True):
        download_link = link['href']
        username = download_link.split('username=')[1]
        # Download file:
        src_file = urllib2.urlopen(download_link)
        file_name = src_file.headers.get('content-disposition').split('filename=')[1]
        output = open( OUTPUT_DIR + '/' + file_name,'wb')
        output.write( src_file.read())
        output.close()
        pass

if __name__ == '__main__':
    process_source()


import anltk

import sys
import time
from camel_tools.utils.dediac import dediac_ar
from camel_tools.utils.transliterate import Transliterator, CharMapper
file_name = sys.argv[1]
from camel_tools.sentiment import SentimentAnalyzer

from camel_tools.sentiment import SentimentAnalyzer

# sa = SentimentAnalyzer.pretrained()

# # Predict the sentiment of a single sentence
# sentiment = sa.predict_sentence('أنا بخير')

# # Predict the sentiment of multiple sentences
# sentences = [
#     'أنا بخير',
#     'أنا لست بخير'
# ]
# sentiments = sa.predict(sentences)
# print(sentiments)
# exit()

with open(file_name) as f:
    file = f.read()
    tic = time.perf_counter()

    file = anltk.transliterate(file, anltk.AR2BW)
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in {dur:0.4} seconds")

    with open('./out_anltk.csv', 'w') as of:
        of.writelines(file)

with open(file_name) as f:
    file = f.read()
    tic = time.perf_counter()
    tra = Transliterator(CharMapper.builtin_mapper('ar2bw'))
    file = tra.transliterate(file)
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in {dur:0.4} seconds")
    with open('./out_camel.csv', 'w') as of:
        of.writelines(file)
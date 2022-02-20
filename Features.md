

## Convert numbers into spoken form (تفقيط) :
```python
anltk.tafqit(1934)
# 'ألف وتسعمائة وأربعة وثلاثون'
anltk.tafqit(1934, anltk.TafqitOptions(is_feminine=True))
# 'ألف وتسعمائة وأربع وثلاثون'
```

## Transliteration. converting between Characters Mapping
```python
# Buckwalter
anltk.transliterate("أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ", anltk.AR2BW)
# '>bjd hwz HTy klmn sEfS qr$t vx* DZg'

# Safe Buckwalter
anltk.transliterate("أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ", anltk.AR2SBW)
# 'Objd hwz HTy klmn sEfS qrct vxV DZg'


anltk.transliterate(">bjd hwz HTy klmn sEfS qr$t vx* DZg", anltk.BW2AR)
# 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'


anltk.transliterate("Objd hwz HTy klmn sEfS qrct vxV DZg", anltk.SBW2AR)
# 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'
```


## Tokenization

```python
anltk.tokenize_words('في السّاعة الثانية, ذهبنا على البيت جميعا!! وعدنا معاً.')
# ['في', 'السّاعة', 'الثانية', ',', 'ذهبنا', 'على', 'البيت', 'جميعا', '!!', 'وعدنا', 'معاً', '.']
```


## Utilities :

```python
# if the literal in anltk.constants.HARAKAT 
anltk.is_tashkeel('ي') # False
anltk.is_tashkeel('ِ') # True 

# if the literal in anltk.constants.ALPHABET
anltk.is_arabic_alpha('h') # False
anltk.is_arabic_alpha('أ') # True

# if a character is shamsi
anltk.is_shamsi('ش')
#	True
# if a character is qamari
anltk.is_qamari('و')
#	True
```


## Preprocessing:
```python
anltk.remove_tashkeel('فرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ')
# 'فراشة ملونة تطير في البستان'

# stop_list contains list of characters that won't be removed
anltk.remove_non_alpha('فرَاdشَةٌ مُلَوَّنَ3ةٌ!', stop_list = '! ')
# 'فراشة ملونة!'

anltk.remove_non_alphanumeric('فرَاdشَةٌ مُلَوَّ3نَةٌ!', stop_list = '! ')
# 'فراشة ملو3نة!'

anltk.remove_non_alphanumeric_and_tashkeel('فرَاdشَةٌ مُلَوَّ3نَةٌ!', stop_list = '! ')
# 'فرَاشَةٌ مُلَوَّ3نَةٌ!'

anltk.remove_kasheeda('بســــم الـــله')
# 'بسم الله'

# Replaces Hamzaat forms ‫ء‬, ,‫آ‬ ‫ؤ‬, ‫ئ‬, ‫ئ‬ with ‫أ
anltk.normalize_hamzat('اللآلئ')
# 'اللألأ'
```


## Constants


```python

anltk.constants.HAMZA
anltk.constants.ALEF_MADDA
anltk.constants.ALEF_HAMZA_ABOVE
anltk.constants.WAW_HAMZA_ABOVE
anltk.constants.ALEF_HAMZA_BELOW
anltk.constants.YEH_HAMZA_ABOVE
anltk.constants.ALEF_NO_HAMZA
anltk.constants.BEH
anltk.constants.TEH_MARBOOTA
anltk.constants.TEH
anltk.constants.THEH
anltk.constants.JEEM
anltk.constants.HAH
anltk.constants.KHAH
anltk.constants.DAL
anltk.constants.THAL
anltk.constants.REH
anltk.constants.ZAIN
anltk.constants.SEEN
anltk.constants.SHEEN
anltk.constants.SAD
anltk.constants.DAD
anltk.constants.TAH
anltk.constants.ZAH
anltk.constants.AIN
anltk.constants.GHAIN
anltk.constants.FEH
anltk.constants.QAF
anltk.constants.KAF
anltk.constants.LAM
anltk.constants.MEEM
anltk.constants.NOON
anltk.constants.HEH
anltk.constants.WAW
anltk.constants.ALEF_MAQSURA
anltk.constants.YEH
anltk.constants.ALEF_WASLA
anltk.constants.PEH
anltk.constants.TCHEH
anltk.constants.VEH
anltk.constants.GAF
anltk.constants.TATWEEL
anltk.constants.TANWEEN_FATHA
anltk.constants.TANWEEN_DAMMA
anltk.constants.TANWEEN_KASRA
anltk.constants.FATHA
anltk.constants.DAMMA
anltk.constants.KASRA
anltk.constants.SHADDA
anltk.constants.SUKUN
anltk.constants.FASLA
anltk.constants.QUESTION_MARK
anltk.constants.FASLA_MANKOOTA
anltk.constants.NOKTATAN
anltk.constants.NESBA
anltk.constants.TA3AJJOB
anltk.constants.KAWS_MAFTOOH
anltk.constants.KAWS_MAKFOOL
anltk.constants.DARB
anltk.constants.JAM3
anltk.constants.KESMA
anltk.constants.TAR7
anltk.constants.YOSAWI
anltk.constants.NOQTA
anltk.constants.SEFR
anltk.constants.WAHED
anltk.constants.ETHNAN
anltk.constants.THALATHA
anltk.constants.ARBA3A
anltk.constants.KHAMSA
anltk.constants.SETTA
anltk.constants.SAB3A
anltk.constants.THAMANEYA
anltk.constants.TES3A
anltk.constants.SMALL_ALEF
anltk.constants.SMALL_WAW
anltk.constants.SMALL_YEH

anltk.constants.ARQAM
# ['٠', '١', '٢', '٣', '٤', '٥', '٦', '٧', '٨', '٩']

anltk.constants.HARAKAT
# ['ً', 'ٌ', 'ٍ', 'َ', 'ُ', 'ِ', 'ّ', 'ْ']

anltk.constants.ALPHABET
#['ء', 'آ', 'أ', 'ؤ', 'إ', 'ئ', 'ا', 'ب', 'ة', 'ت', 'ث', 'ج', 'ح', 'خ', 'د', 'ذ', 'ر', 'ز', 'س', 'ش', 'ص', 'ض', 'ط', 'ظ', 'ع', 'غ', 'ف', 'ق', 'ك', 'ل', 'م', 'ن', 'ه', 'و', 'ى', 'ي']
```
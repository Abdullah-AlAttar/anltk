import anltk

# def test_has_spaces():

#     ar_text = 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_empty():

#     ar_text = ''
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Has_double_consecutive_shadda():

#     ar_text = 'بسّّم'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_first_character_tashkeel():

#     ar_text = 'ًبسم'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_First_Character_WAW_HAMZA():

#     ar_text = 'ؤامر'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_First_Character_YEH_HAMZA():

#     ar_text = 'ئاسر'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Alef_Maqsura_not_last_Character():

#     ar_text = 'ىا ليلى'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Teh_Marbuta_not_last_Character():

#     ar_text = 'ىا لةيلى'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Three_consectuve_harakat():

#     ar_text = 'ىاًَُ لةيلى'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_double_Teh_Marbuta():

#     ar_text = 'ىا لةةيلى'
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Valid():

#     ar_text = 'فأسقيناكموه'
#     assert anltk.is_valid_kalima(ar_text) == True

# def test_Valid1():

#     ar_text = 'فأسًقيٍنََاّكمٍوُه'
#     assert anltk.is_valid_kalima(ar_text) == True


def test_tokenize():

    text = 'بسم الله@ الرحمن23 الرحيم.'

    assert anltk.tokenize_words(text) == [
        'بسم', 'الله', '@', 'الرحمن', '23', 'الرحيم', '.'
    ]





def test_transliterate():

    assert anltk.transliterate(
        'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ',
        anltk.AR2BW) == '>bjd hwz HTy klmn sEfS qr$t vx* DZg'

    # Safe Buckwalter
    assert anltk.transliterate(
        'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ',
        anltk.AR2SBW) == 'Objd hwz HTy klmn sEfS qrct vxV DZg'

    assert anltk.transliterate(
        '>bjd hwz HTy klmn sEfS qr$t vx* DZg',
        anltk.BW2AR) == 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'

    assert anltk.transliterate(
        'Objd hwz HTy klmn sEfS qrct vxV DZg',
        anltk.SBW2AR) == 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'


def test_remove_tashkeel():
    assert anltk.remove_tashkeel('فرَاشَةٌ مُلَوَّنَةٌ') == 'فراشة ملونة'


def test_remove_non_alpha():
    assert anltk.remove_non_alpha('فرَاdشَةٌ مُلَوَّنَ3ةٌ!',
                                  stop_list='! ') == 'فراشة ملونة!'
    assert anltk.remove_non_alphanumeric('فرَاdشَةٌ مُلَوَّ3نَةٌ!',
                                         stop_list='! ') == 'فراشة ملو3نة!'

    assert anltk.remove_non_alphanumeric_and_tashkeel(
        'فرَاdشَةٌ مُلَوَّ3نَةٌ!', stop_list='! ') == 'فرَاشَةٌ مُلَوَّ3نَةٌ!'
    assert anltk.remove_kasheeda('بســــم الـــله') == 'بسم الله'


def test_remove_if():
    assert anltk.remove_if('باب الحارة', ' ', lambda x: x == 'ب') == 'ا الحارة'


def test_folding():
    assert anltk.fold_white_spaces(
        'بسم     الله    الرحمن ال   رحيم\t\t') == 'بسم الله الرحمن ال رحيم '


def test_splitting():
    assert anltk.split('ffsl بسم اللهْ') == ['ffsl', 'بسم', 'اللهْ']
    assert anltk.split('يا الله, يا رحمن يا رحيم.',
                       delimeters='.,',
                       keep_delimeters=False) == [
                           'يا الله', ' يا رحمن يا رحيم'
                       ]
    assert anltk.split('يا الله, يا رحمن يا رحيم.',
                       delimeters='.,',
                       keep_delimeters=True) == [
                           'يا الله,', ' يا رحمن يا رحيم.'
                       ]


def test_replace():
    assert anltk.replace_if('ffsl بسم اللهْ',
                            lambda x: not anltk.is_arabic_alpha(x),
                            '!') == '!!!!!بسم!الله!'


def test_normalize():
    assert anltk.normalize_to_heh(
        'الحديقة! الجديدةُ كانت مشرقة إشراقةً تهيم على الشفاه'
    ) == 'الحديقه! الجديدهُ كانت مشرقه إشراقهً تهيم على الشفاه'
    assert anltk.normalize_to_teh(
        'الحديقه! الجديدهُ كانت مشرقه إشراقهً تهيم على الشفاه'
    ) == 'الحديقة! الجديدةُ كانت مشرقة إشراقةً تهيم على الشفاة'


def test_tokenize_if():
    text = "إِنَّ الَّذِينَ كَفَرُوا سَوَاءٌ عَلَيْهِمْ أَأَنذَرْتَهُمْ أَمْ لَمْ تُنذِرْهُمْ لَا يُؤْمِنُونَ ."

    assert anltk.tokenize_if(text,
                             [anltk.is_tashkeel, anltk.is_arabic_alpha]) == [
                                 (1, 'إ'), (0, 'ِ'), (1, 'ن'), (0, 'َّ'),
                                 (-1, ' '), (1, 'ال'), (0, 'َّ'), (1, 'ذ'),
                                 (0, 'ِ'), (1, 'ين'), (0, 'َ'), (-1, ' '),
                                 (1, 'ك'), (0, 'َ'), (1, 'ف'), (0, 'َ'),
                                 (1, 'ر'), (0, 'ُ'), (1, 'وا'), (-1, ' '),
                                 (1, 'س'), (0, 'َ'), (1, 'و'), (0, 'َ'),
                                 (1, 'اء'), (0, 'ٌ'), (-1, ' '), (1, 'ع'),
                                 (0, 'َ'), (1, 'ل'), (0, 'َ'), (1, 'ي'),
                                 (0, 'ْ'), (1, 'ه'), (0, 'ِ'), (1, 'م'),
                                 (0, 'ْ'), (-1, ' '), (1, 'أ'), (0, 'َ'),
                                 (1, 'أ'), (0, 'َ'), (1, 'نذ'), (0, 'َ'),
                                 (1, 'ر'), (0, 'ْ'), (1, 'ت'), (0, 'َ'),
                                 (1, 'ه'), (0, 'ُ'), (1, 'م'), (0, 'ْ'),
                                 (-1, ' '), (1, 'أ'), (0, 'َ'), (1, 'م'),
                                 (0, 'ْ'), (-1, ' '), (1, 'ل'), (0, 'َ'),
                                 (1, 'م'), (0, 'ْ'), (-1, ' '), (1, 'ت'),
                                 (0, 'ُ'), (1, 'نذ'), (0, 'ِ'), (1, 'ر'),
                                 (0, 'ْ'), (1, 'ه'), (0, 'ُ'), (1, 'م'),
                                 (0, 'ْ'), (-1, ' '), (1, 'ل'), (0, 'َ'),
                                 (1, 'ا'), (-1, ' '), (1, 'ي'), (0, 'ُ'),
                                 (1, 'ؤ'), (0, 'ْ'), (1, 'م'), (0, 'ِ'),
                                 (1, 'ن'), (0, 'ُ'), (1, 'ون'), (0, 'َ'),
                                 (-1, ' .')
                             ]
def test_tafqit():
    opts = anltk.TafqitOptions()
    assert anltk.tafqit(2000, opts) == "ألفان"
    assert anltk.tafqit(2020, opts) == "ألفان وعشرون"
    assert anltk.tafqit(15000120, opts) == "خمسة عشر مليونًا ومائة وعشرون"
    assert anltk.tafqit(0, opts) == "صفر"
    assert anltk.tafqit(1, opts) == "واحد"
    assert anltk.tafqit(2, opts) == "اثنان"
    assert anltk.tafqit(3, opts) == "ثلاثة"
    assert anltk.tafqit(4, opts) == "أربعة"
    assert anltk.tafqit(5, opts) == "خمسة"
    assert anltk.tafqit(6, opts) == "ستة"
    assert anltk.tafqit(7, opts) == "سبعة"
    assert anltk.tafqit(8, opts) == "ثمانية"
    assert anltk.tafqit(9, opts) == "تسعة"  
    assert anltk.tafqit(10, opts) == "عشرة"
    assert anltk.tafqit(22, opts) == "اثنان وعشرون"
    assert anltk.tafqit(30, opts) == "ثلاثون"   
    assert anltk.tafqit(119, opts) == "مائة وتسعة عشر"
    assert anltk.tafqit(120, opts) == "مائة وعشرون"
    assert anltk.tafqit(199, opts) == "مائة وتسعة وتسعون"   
    assert anltk.tafqit(200, opts) == "مائتان"  
    assert anltk.tafqit(300, opts) == "ثلاثمائة"
    assert anltk.tafqit(311, opts) == "ثلاثمائة وأحد عشر"   
    assert anltk.tafqit(1019, opts) == "ألف وتسعة عشر"
    assert anltk.tafqit(3019, opts) == "ثلاثة آلاف وتسعة عشر"
    assert anltk.tafqit(10000, opts) == "عشرة آلاف"
    assert anltk.tafqit(10500, opts) == "عشرة آلاف وخمسمائة"
    assert anltk.tafqit(100500, opts) == "مائة ألف وخمسمائة"
    assert anltk.tafqit(110500, opts) == "مائة وعشرة آلاف وخمسمائة"
    assert anltk.tafqit(-110500, opts) == "سالب مائة وعشرة آلاف وخمسمائة"
    assert anltk.tafqit(99999, opts) == "تسعة وتسعون ألفًا وتسعمائة وتسعة وتسعون"
    assert anltk.tafqit(999999, opts) == "تسعمائة وتسعة وتسعون ألفًا وتسعمائة وتسعة وتسعون"
    assert anltk.tafqit(1000000000, opts) == "مليار"
    assert anltk.tafqit(1000000001, opts) == "مليار وواحد"
    assert anltk.tafqit(10000000000, opts) == "عشرة مليارات"
    assert anltk.tafqit(1000000000000, opts) == "ترليون"
    
    opts.is_feminine = True
    assert anltk.tafqit(2000, opts) == "ألفان"
    assert anltk.tafqit(2020, opts) == "ألفان وعشرون"
    assert anltk.tafqit(15000120, opts) == "خمسة عشر مليونًا ومائة وعشرون"
    assert anltk.tafqit(0, opts) == "صفر"
    assert anltk.tafqit(1, opts) == "واحدة"
    assert anltk.tafqit(2, opts) == "اثنتان"
    assert anltk.tafqit(3, opts) == "ثلاث"
    assert anltk.tafqit(4, opts) == "أربع"
    assert anltk.tafqit(5, opts) == "خمس"
    assert anltk.tafqit(6, opts) == "ست"
    assert anltk.tafqit(7, opts) == "سبع"
    assert anltk.tafqit(8, opts) == "ثمان"
    assert anltk.tafqit(9, opts) == "تسع"   
    assert anltk.tafqit(10, opts) == "عشر"
    assert anltk.tafqit(22, opts) == "اثنتان وعشرون"
    assert anltk.tafqit(30, opts) == "ثلاثون"   
    assert anltk.tafqit(119, opts) == "مائة وتسع عشرة"
    assert anltk.tafqit(120, opts) == "مائة وعشرون"
    assert anltk.tafqit(199, opts) == "مائة وتسع وتسعون"    
    assert anltk.tafqit(200, opts) == "مائتان"  
    assert anltk.tafqit(300, opts) == "ثلاثمائة"
    assert anltk.tafqit(311, opts) == "ثلاثمائة وإحدى عشرة" 
    assert anltk.tafqit(1019, opts) == "ألف وتسع عشرة"
    assert anltk.tafqit(3019, opts) == "ثلاثة آلاف وتسع عشرة"
    assert anltk.tafqit(10000, opts) == "عشرة آلاف"
    assert anltk.tafqit(10500, opts) == "عشرة آلاف وخمسمائة"
    assert anltk.tafqit(100500, opts) == "مائة ألف وخمسمائة"
    assert anltk.tafqit(110500, opts) == "مائة وعشرة آلاف وخمسمائة"
    assert anltk.tafqit(-110500, opts) == "سالب مائة وعشرة آلاف وخمسمائة"
    assert anltk.tafqit(99999, opts) == "تسعة وتسعون ألفًا وتسعمائة وتسع وتسعون"
    assert anltk.tafqit(999999, opts) == "تسعمائة وتسعة وتسعون ألفًا وتسعمائة وتسع وتسعون"
    assert anltk.tafqit(1000000000, opts) == "مليار"
    assert anltk.tafqit(1000000001, opts) == "مليار وواحدة"
    assert anltk.tafqit(10000000000, opts) == "عشرة مليارات"
    assert anltk.tafqit(1000000000000, opts) == "ترليون"
    
    
def test_noise():
    gen = anltk.NoiseGenerator()
    gen.set_seed(3)
    
    assert gen.insert_random_chars('صوت صفير البلبل') == 'صوت صشفير البلبل'
    assert gen.swap_adjacent_chars('صوت صفير البلبل') == 'صوت فصير البلبل'
    assert gen.remove_random_chars('صوت صفير البلبل') == 'صوت صفير البلل'
    assert gen.replace_random_chars('صوت صفير البلبل') == 'صوت صفير ءلبلبل'
    assert gen.join_random_words('صوت صفير البلبل') == 'صوت صفيرالبلبل'
    assert gen.swap_random_words('صوت صفير البلبل') == 'صفير صوت البلبل'
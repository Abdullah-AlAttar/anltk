import anltk


# def test_has_spaces():

#     ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_empty():

#     ar_text = ""
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Has_double_consecutive_shadda():

#     ar_text = "بسّّم"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_first_character_tashkeel():

#     ar_text = "ًبسم"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_First_Character_WAW_HAMZA():

#     ar_text = "ؤامر"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_First_Character_YEH_HAMZA():

#     ar_text = "ئاسر"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Alef_Maqsura_not_last_Character():

#     ar_text = "ىا ليلى"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Teh_Marbuta_not_last_Character():

#     ar_text = "ىا لةيلى"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Three_consectuve_harakat():

#     ar_text = "ىاًَُ لةيلى"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_double_Teh_Marbuta():

#     ar_text = "ىا لةةيلى"
#     assert anltk.is_valid_kalima(ar_text) == False

# def test_Valid():

#     ar_text = "فأسقيناكموه"
#     assert anltk.is_valid_kalima(ar_text) == True

# def test_Valid1():

#     ar_text = "فأسًقيٍنََاّكمٍوُه"
#     assert anltk.is_valid_kalima(ar_text) == True


def test_tokenize():

    text = "بسم الله@ الرحمن23 الرحيم."

    assert anltk.tokenize_words(
        text) == ["بسم", "الله", "@", "الرحمن", "23", "الرحيم", "."]


def test_tafqeet():

    assert anltk.tafqeet(394) == "ثلاثمئة و أربعة و تسعون"


def test_transliterate():

    assert anltk.transliterate("أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ",
                               anltk.AR2BW) == '>bjd hwz HTy klmn sEfS qr$t vx* DZg'

    # Safe Buckwalter
    assert anltk.transliterate("أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ",
                               anltk.AR2SBW) == 'Objd hwz HTy klmn sEfS qrct vxV DZg'

    assert anltk.transliterate(">bjd hwz HTy klmn sEfS qr$t vx* DZg",
                               anltk.BW2AR) == 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'

    assert anltk.transliterate("Objd hwz HTy klmn sEfS qrct vxV DZg",
                               anltk.SBW2AR) == 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'

def test_remove_tashkeel():
    assert anltk.remove_tashkeel("فرَاشَةٌ مُلَوَّنَةٌ") == "فراشة ملونة"


def test_remove_non_alpha():
    assert anltk.remove_non_alpha('فرَاdشَةٌ مُلَوَّنَ3ةٌ!', stop_list = '! ') ==  'فراشة ملونة!'
    assert anltk.remove_non_alphanumeric('فرَاdشَةٌ مُلَوَّ3نَةٌ!', stop_list = '! ') ==  'فراشة ملو3نة!'

    assert anltk.remove_non_alphanumeric_and_tashkeel('فرَاdشَةٌ مُلَوَّ3نَةٌ!', stop_list = '! ') == 'فرَاشَةٌ مُلَوَّ3نَةٌ!'
    assert anltk.remove_kasheeda('بســــم الـــله') ==  'بسم الله'


def test_remove_if():
    assert anltk.remove_if('باب الحارة', " ", lambda x : x == 'ب') == 'ا الحارة'

def test_folding():
    assert anltk.fold_white_spaces('بسم     الله    الرحمن ال   رحيم\t\t') == 'بسم الله الرحمن ال رحيم\t'

def test_splitting():
    assert anltk.split("ffsl بسم اللهْ") == ['ffsl', 'بسم', 'اللهْ']
    assert anltk.split("يا الله, يا رحمن يا رحيم." , delimeters=".," , keep_delimeters=False) == ['يا الله', ' يا رحمن يا رحيم']
    assert anltk.split("يا الله, يا رحمن يا رحيم." , delimeters=".," , keep_delimeters=True) == ['يا الله,', ' يا رحمن يا رحيم.']
import anltk



def test_has_spaces():

    ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ"
    assert anltk.is_valid_kalima(ar_text) == False

def test_empty():

    ar_text = ""
    assert anltk.is_valid_kalima(ar_text) == False

def test_Has_double_consecutive_shadda():

    ar_text = "بسّّم"
    assert anltk.is_valid_kalima(ar_text) == False

def test_first_character_tashkeel():

    ar_text = "ًبسم"
    assert anltk.is_valid_kalima(ar_text) == False

def test_First_Character_WAW_HAMZA():

    ar_text = "ؤامر"
    assert anltk.is_valid_kalima(ar_text) == False

def test_First_Character_YEH_HAMZA():

    ar_text = "ئاسر"
    assert anltk.is_valid_kalima(ar_text) == False

def test_Alef_Maqsura_not_last_Character():

    ar_text = "ىا ليلى"
    assert anltk.is_valid_kalima(ar_text) == False

def test_Teh_Marbuta_not_last_Character():

    ar_text = "ىا لةيلى"
    assert anltk.is_valid_kalima(ar_text) == False

def test_Three_consectuve_harakat():

    ar_text = "ىاًَُ لةيلى"
    assert anltk.is_valid_kalima(ar_text) == False

def test_double_Teh_Marbuta():

    ar_text = "ىا لةةيلى"
    assert anltk.is_valid_kalima(ar_text) == False

def test_Valid():

    ar_text = "فأسقيناكموه"
    assert anltk.is_valid_kalima(ar_text) == True

def test_Valid1():

    ar_text = "فأسًقيٍنََاّكمٍوُه"
    assert anltk.is_valid_kalima(ar_text) == True


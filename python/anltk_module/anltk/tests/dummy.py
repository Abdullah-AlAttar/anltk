# %%
import anltk


print(anltk.__version__)

print(anltk.__doc__)

print(anltk.replace('بسم الله',
 {
	  'ل' : 'ر' ,
 	  ' ' : 'd'
 }
))

print(anltk.replace_str('بسم الله',
 {
	 'ال' : 'الْ', 
	 'بس' : 'ييي', 

 }
))

# %%

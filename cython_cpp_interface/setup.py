from setuptools import setup
# from distutils.core import setup, Extension
from Cython.Build import cythonize

#Run $ python setup.py build_ext --inplace

setup(
    ext_modules=cythonize("rect.pyx", language_level=3)
)

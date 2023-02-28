from setuptools import setup, find_packages

setup(
    name="pyblas",
    version="0.1",
    keywords=["data", "pyblas"],
    long_description="lapack implement for python",
    license="FDU Licence",

    url="https://github.com/yqxd/pyblas",
    author="Zhenyu Xu",
    author_email="22210980117@m.fudan.edu.cn",

    packages=find_packages(),
    include_package_data=True,
    platforms="any",
    install_requires=[],

    scripts=[]
)

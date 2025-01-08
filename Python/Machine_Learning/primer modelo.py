import pandas as pd
datos = pd.read_csv("celsius.csv")
datos.info()
datos.head()


import seabron as sb
sb.scatterplot(x="celsius", y="fahrenheit", data=datos)

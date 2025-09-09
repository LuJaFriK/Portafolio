from mcp.server.fastmcp import FastMCP #Libreria mcp server
import os

mcp = FastMCP("Ejecutar_bash",host="0.0.0.0",port=8080)

#Variables de entorno
variable = "carpeta/archivo.arch"

@mcp.tool(name="nombre_de_la_funcion",description="contexto_de_la_funcion")
def nombre_de_la_funcion(variable1: int,variable2: float,variable3: object) -> str: #Lo ideal es retornar strings
    pass #algoritmo    
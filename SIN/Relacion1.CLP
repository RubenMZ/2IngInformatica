1.

(deftemplate persona
(slot nombre (type STRING))
(slot apellido(type STRING))
(slot color-ojos (type SYMBOL)(default marron))
(slot altura (type FLOAT)(default 1.80))
(slot edad(type INTEGER)(default 18))
)

2.

(deftemplate paciente
(slot nombre (type STRING))
(multislot apellidos(type STRING))
(slot dni (type SYMBOL))
(slot seguro-medico (type STRING))
)

(deftemplate visita
(slot dni (type SYMBOL))
(slot fecha (type SYMBOL))
(multislot sintomas (type STRING))
(multislot pruebas (type STRING))
(multislot medicacion (type STRING))
)

Ej: (assert (paciente(nombre "Ruben")(apellidos "Medina" "Zamorano")(dni 45667812H)(seguro-medico "Adeslas")))
Ej: (assert (visita(dni 46068656R)(fecha 20/03/2015)(sintomas "dolor de cabeza")(pruebas "garganta")(medicacion "paracetamol")))

3.
(deftemplate vuelos
(slot ciudad (type SYMBOL))
(multislot llegadas (type SYMBOL))
(multislot salidas (type SYMBOL))
)

Ej: (deffacts viajes (vuelos(ciudad lisboa)(llegadas roma)(salidas madrid paris))(vuelos (ciudad paris)(salidas roma)(llegadas lisboa estocolmo)) )

4.
(deftemplate familia
(slot nombre (default ?NONE)(type STRING))
(slot padre (default ?NONE)(type STRING))
(slot madre (default ?NONE)(type STRING))
(multislot hermanos (type STRING))
(multislot hijos (type STRING)) 
(multislot tios (type STRING))
)

Ej. (deffacts prueba 
	(familia (nombre "Ruben")
		(padre "Jose")
		(madre "Maria")
		(tios "Antonio" "Carmen"))
	(familia (nombre "Ruben")
		(padre "Jose")
		(madre "Maria")
		(tios "Antonio" "Carmen")
		(hijos "Carlos")
		(hermanos "Sandra"))
)

5.

(deftemplate libro
	(slot titulo (type STRING)(default ?NONE))
	(multislot autor (type STRING) (default ?NONE))
	(slot fecha (type INTEGER))
	(slot editorial (type STRING))
)

ej.
(deffacts pruebaLibros 
	(libro 
		(titulo "Aspectos Basico de la Inteligencia Artificial") 
		(autor "Mira, J" "Delgado, A" "Boticario, J G" "Diez D J")
		(fecha 1995)
		(editorial "Sanz y Torres"))
	(libro 
		(titulo "Problemas resueltos de inteligencia artificial aplicada: busqueda y representacion") 
		(autor "Galan, S F" "Boticario, J G" "Mira, J")
		(fecha 1998)
		(editorial "Addison-Wesley Iberoamericana S.A."))
	(libro 
		(titulo "Inteligencia Artificial. 2ª Edicion") 
		(autor "Rich, E" "Knight, K")
		(fecha 1994)
		(editorial "McGraw-Hill"))
)

6.
(deftemplate coche
	(slot modelo (type STRING) )
	(slot motor (type STRING) )
	(slot capacidad-motor (type NUMBER) )
	(slot puertas (type INTEGER)(allowed-integers 3 5) )
	(slot color (type STRING) )
)

(deftemplate venta
	(slot coche (type STRING))
	(slot vendedor (type STRING))
	(slot fecha (type SYMBOL))
	(slot cliente (type STRING))
)

(deffacts ejer6
	(coche (modelo "clio")
		(motor "gasolina")
		(capacidad-motor 1600)
		(puertas 4)
		(color "azul"))
	(venta (coche "megane")
		(vendedor "Juan Perez")
		(fecha 10/10/2003)
		(cliente "Esteban Losada"))
)

7.

(deffacts clases 
	(clases-animales mamiferos reptiles aves )
		(clases-mamiferos roedores felinos)
			(clases-roedores rata ardilla)
			(clases-felinos tigre lince jaguar)
		(clases-reptiles serpientes)
			(clases-serpientes boa cobra)
		(clases-aves rapaces)
			(clases-rapaces diurnas nocturnas)
				(clases-diurnas halcon gavilan)
				(clases-nocturnas buho lechuza)
)

8.

(deftemplate lista
	(multislot obtenidos (type STRING))
	(multislot comprar (type STRING))
)

(deftemplate plato
(slot nombre (type STRING))
(multislot ingredientes (type STRING))
)

(deffacts ejer8
	(plato (nombre "Pisto")
	(ingredientes "pimientos verdes" 
		"pimientos rojos" 
		"berenjenas" 
		"calabacines"
		"cebollas" 
		"tomate triturado"
		"sal"
		"aceite")
	)
	(plato (nombre "tortilla de patatas")
		(ingredientes "huevos"
		"patatas"
		"cebollas"
		"aceite"
		"sal")
	)
	(lista 
		(obtenidos "pimientos verdes" "pimientos rojos" "cebollas" "aceite")
		(comprar "calabacines" "tomate triturado" "sal" "huevos" "patatas"))
)
	(duplicate 3 (obtenidos "calabacines" "tomate triturado" "sal" "huevos" "patatas"))

	(assert(lista (obtenidos "pimientos verdes" "pimientos rojos" "cebollas" "aceite" "calabacines" "tomate triturado" "sal" "huevos" "patatas")
		))

	(assert(lista (obtenidos "pimientos verdes" "pimientos rojos" "aceite" "calabacines" "sal" "huevos" "patatas")
		))



9.
(deftemplate barco
	(slot espacio-ocupado (type INTEGER)(range 1 4)(default ?NONE))
	(slot tipo (type SYMBOL)(allowed-symbols patrullera dragaminas fragata acorazado destructor portaaviones)(default ?NONE))
	(slot estado (type SYMBOL)(allowed-symbols indemne tocado hundido)(default indemne))
)

(deffacts ejer9
(barco (espacio-ocupado 4)(tipo fragata)(estado tocado))
(barco (espacio-ocupado 2)(tipo patrullera))
(barco (espacio-ocupado 3)(tipo dragaminas)(estado hundido))
)

10.
(deftemplate alumno
(multislot apellidos (type STRING )(default ?NONE))
(slot nombre (type STRING)(default ?NONE))
(slot examen1 (type FLOAT)(range 0.0 10.0))
(slot examen2 (type FLOAT)(range 0.0 10.0))
(slot trabajo (type FLOAT)(range 0.0 10.0))
(slot nota-media (type FLOAT)(range 0.0 10.0))
(slot nombre-grupo (type STRING))
(multislot integrantes (type STRING)(cardinality 1 4))
)

(deffacts ejer10
	(alumno (nombre "Antonio") (apellidos "Luque" "Paez")(examen1 6.7)(examen2 5.5)(nombre-grupo "Ganadores")(integrantes "Antonio" "Carlos" "David"))
	(alumno (nombre "David") (apellidos "Perez" "Alcantara")(examen1 8.0)(examen2 2.3)(nombre-grupo "Ganadores")(integrantes "Antonio" "Carlos" "David"))
	(alumno (nombre "Miguel Angel") (apellidos "Sanchez" )(examen1 1.5)(examen2 7.2)(nombre-grupo "Ganadores")(integrantes "Miguel" "Jose" "Antonio" "Sergio"))
)
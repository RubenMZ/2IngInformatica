;Ejercicio2
(deftemplate animal
	(slot nombre)
	(slot sonido)
)

(deffacts animales
	(animal(nombre perro)(sonido guauguau))
	(animal(nombre gato)(sonido miau))
	(animal(nombre pato)(sonido cuac))
	(animal(nombre vaca)(sonido mu))
	(animal(nombre oveja)(sonido be))
	(animal(nombre gallo)(sonido kikiriki))
)

(defrule sonido
	(animal (nombre ?n)(sonido ?s))
	=>
	(printout t "Se trata de un/a " ?n crlf)
)

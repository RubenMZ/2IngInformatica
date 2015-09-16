;Ejercicio1
(deffacts animales
	(sonido guauguau)
	(sonido miau)
	(sonido cuac)
	(sonido mu)
	(sonido be)
	(sonido kikiriki)
)

(defrule perro
	(sonido guauguau)
	=>
	(printout t "Se trata de un perro" crlf)
)

(defrule gato
	(sonido miau)
	=>
	(printout t "Se trata de un gato" crlf)
)

(defrule pato
	(sonido cuac)
	=>
	(printout t "Se trata de un pato" crlf)
)

(defrule vaca
	(sonido mu)
	=>
	(printout t "Se trata de una vaca" crlf)
)

(defrule oveja
	(sonido be)
	=>
	(printout t "Se trata de una oveja" crlf)
)

(defrule gallo
	(sonido kikiriki)
	=>
	(printout t "Se trata de un gallo" crlf)
)
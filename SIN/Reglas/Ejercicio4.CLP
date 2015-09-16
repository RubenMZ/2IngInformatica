;Ejercicio4

(deffacts hechos
	(datos 1 2 3 7)
	(datos 2 5 1 8)
	(datos 5 1 1)
	(datos 4 1 5 2)
	(datos 4 1 2 9 12)
	(datos 12 14)
)

(defrule comprubaDatos 
	(datos ?x&:(numberp ?x) $?resto ?y&:(numberp ?y))
	(test(= (mod ?x 2) 0))
	(test(< ?x ?y))	
	=>
	(printout t "Los datos " ?x " ... "?y " cumplen la regla" crlf)
)
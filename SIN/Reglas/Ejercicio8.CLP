;Ejercicio8

(deffacts ejercicio8 (vector v1 1 3 4 5)(vector v2 3 4 2)(vector v3 2 3 4 3))

(defrule vectorNoOrdenado
	(vector ?nombre $? ?x ?y $?)
	(test (> ?x ?y))	
=>
	(printout t "El vector no esta ordenado: " ?nombre crlf)
)
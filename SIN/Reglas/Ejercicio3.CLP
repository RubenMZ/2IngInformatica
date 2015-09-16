;Ejercicio3

(deffacts hechos
	(datos 3 4)
	(datos 5 9)
	(datos 7 7)
	(datos 8 2)
)

(defrule segundoMayor
	?h<-(datos ?n1&:(numberp ?n1) ?n2&:(numberp ?n2))
	(test(< ?n1 ?n2))
	=>
	(printout t ?h " - El valor " ?n1 " es menor que " ?n2 crlf)
)
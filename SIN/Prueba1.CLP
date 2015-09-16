(deftemplate persona "datos de la persona en cuestion"
	(slot nombre (default ?NONE))
	(slot edad (default 18) (range 18 65) (type INTEGER))
	(multislot direccion)
)

(assert(persona(nombre Pepe)))
(assert(persona(nombre Ruben)(edad 19)))
(assert(persona(nombre Carlos)(edad 50)(direccion Alcala)))

(deftemplate dato
(slot w (default ?NONE))
(slot x (default ?DERIVE))
(slot y (default(gensym*)))
(slot z (default-dynamic(gensym*))))

(deffacts Alumnos "mis companieros :D" (persona(nombre Pepe)(direccion Montero)) (persona(nombre Fran)(edad 21)))
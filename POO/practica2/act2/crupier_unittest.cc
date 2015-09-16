// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "persona.h"
#include "gtest/gtest.h"
#include "crupier.h"

TEST(Persona, ConstructorParametrosDefecto) {
  Persona p("33XX");
  
  EXPECT_EQ("33XX", p.getDNI());
  EXPECT_EQ("", p.getNombre());
  EXPECT_EQ("", p.getApellidos());
  EXPECT_EQ("", p.getDireccion());
  EXPECT_EQ("", p.getLocalidad());
  EXPECT_EQ("", p.getProvincia());
  EXPECT_EQ("", p.getPais());
  EXPECT_EQ(", ", p.getApellidosyNombre());
}
 
TEST(Persona, ConstructorParametros) {
  Persona p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  
  EXPECT_EQ("44XX", p.getDNI());
  EXPECT_EQ("Carlos", p.getNombre());
  EXPECT_EQ("Gutierrez", p.getApellidos());
  EXPECT_EQ("C/ Mesa 1", p.getDireccion());
  EXPECT_EQ("Aguilar", p.getLocalidad());
  EXPECT_EQ("Sevilla", p.getProvincia());
  EXPECT_EQ("España", p.getPais());
  EXPECT_EQ("Gutierrez, Carlos", p.getApellidosyNombre());
}

TEST(Persona, ConstructorCopiaDefecto) {
  Persona p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Persona q(p);
  Persona r=q;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
  
  EXPECT_EQ("44XX", r.getDNI());
  EXPECT_EQ("Carlos", r.getNombre());
  EXPECT_EQ("Gutierrez", r.getApellidos());
  EXPECT_EQ("C/ Mesa 1", r.getDireccion());
  EXPECT_EQ("Aguilar", r.getLocalidad());
  EXPECT_EQ("Sevilla", r.getProvincia());
  EXPECT_EQ("España", r.getPais());
  EXPECT_EQ("Gutierrez, Carlos", r.getApellidosyNombre());
}

TEST(Persona, OperadorIgualDefecto) {
  Persona p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Persona q("66FF");
  q=p;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
}

TEST(Crupier, ConstructorParametrosDefecto) {
  Crupier c("33XX", "12345");
  
  EXPECT_EQ("33XX", c.getDNI());
  EXPECT_EQ("12345", c.getCodigoCrupier());
  EXPECT_EQ("", c.getNombre());
  EXPECT_EQ("", c.getApellidos());
  EXPECT_EQ("", c.getDireccion());
  EXPECT_EQ("", c.getLocalidad());
  EXPECT_EQ("", c.getProvincia());
  EXPECT_EQ("", c.getPais());
  EXPECT_EQ(", ", c.getApellidosyNombre());
}

TEST(Crupier, ConstructorCopiaDefecto) {
  Crupier p("44XX", "12345", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Crupier q(p);
  Crupier r=q;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("12345", q.getCodigoCrupier());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
  
  EXPECT_EQ("44XX", r.getDNI());
  EXPECT_EQ("12345", r.getCodigoCrupier());
  EXPECT_EQ("Carlos", r.getNombre());
  EXPECT_EQ("Gutierrez", r.getApellidos());
  EXPECT_EQ("C/ Mesa 1", r.getDireccion());
  EXPECT_EQ("Aguilar", r.getLocalidad());
  EXPECT_EQ("Sevilla", r.getProvincia());
  EXPECT_EQ("España", r.getPais());
  EXPECT_EQ("Gutierrez, Carlos", r.getApellidosyNombre());
}

TEST(Crupier, Modificador){

	Crupier c("4606...","1024");
	c.setCodigoCrupier("1036");
	c.setPais("Esp");
	
	EXPECT_EQ("4606...", c.getDNI());
  	EXPECT_EQ("1036", c.getCodigoCrupier());
  	EXPECT_EQ("Esp", c.getPais());
	
	

}

 

#include "rdf.h"

#include <iostream>


int main(void)
/*----------*/
{
  rdf::Graph g ;

  std::string turtle = R"(
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix dcterms: <http://purl.org/dc/terms/> .
@prefix map:  <http://www.biosignalml.org/ontologies/2011/02/mapping#> .
@prefix :     <http://www.biosignalml.org/mappings/> .

:label
  a map:Mapping ;
  rdfs:label "label" ;
  map:property rdfs:label
  .

:comment
  a map:Mapping ;
  rdfs:comment "comment" ;
  map:property rdfs:comment
  .

:description
  a map:Mapping ;
  rdfs:label "description" ;
  map:property dcterms:description
  .

  )" ;

  std::string xml = R"(
<rdf:RDF xmlns:dcterms="http://purl.org/dc/terms/"
         xmlns:map="http://www.biosignalml.org/ontologies/2011/02/mapping#"
         xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
         xmlns:rdfs="http://www.w3.org/2000/01/rdf-schema#"
         xmlns="http://www.biosignalml.org/mappings/">
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/comment">
    <map:property rdf:resource="http://www.w3.org/2000/01/rdf-schema#comment"/>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/comment">
    <rdf:type rdf:resource="http://www.biosignalml.org/ontologies/2011/02/mapping#Mapping"/>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/comment">
    <rdfs:comment>comment</rdfs:comment>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/description">
    <map:property rdf:resource="http://purl.org/dc/terms/description"/>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/description">
    <rdf:type rdf:resource="http://www.biosignalml.org/ontologies/2011/02/mapping#Mapping"/>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/description">
    <rdfs:label>description</rdfs:label>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/label">
    <map:property rdf:resource="http://www.w3.org/2000/01/rdf-schema#label"/>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/label">
    <rdf:type rdf:resource="http://www.biosignalml.org/ontologies/2011/02/mapping#Mapping"/>
  </rdf:Description>
  <rdf:Description rdf:about="http://www.biosignalml.org/mappings/label">
    <rdfs:label>label</rdfs:label>
  </rdf:Description>
</rdf:RDF>
  )" ;

//  g.parseString(turtle, rdf::Graph::Format::TURTLE) ;
//  g.parseString(xml, rdf::Graph::Format::RDFXML, "http://base.org") ;
//  g.parseResource("file:///Users/dave/biosignalml/aobject/build/test.xml", rdf::Graph::Format::RDFXML) ;
//  g.parseResource("test.xml", rdf::Graph::Format::RDFXML) ;

//  g.parseResource("http://demo.biosignalml.org/physiobank/mitdb/102/signal/ECG1") ;
  g.parseResource("http://demo.biosignalml.org/physiobank/mitdb/102") ;


  std::cout << g.serialise(rdf::Graph::Format::TURTLE) << std::endl ;


  rdf::Statement in1(rdf::URI("http://www.biosignalml.org/mappings/comment"),
                    rdf::URI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type"),
                    rdf::URI("http://www.biosignalml.org/ontologies/2011/02/mapping#Mapping")) ;
  rdf::Statement out1(rdf::URI("http://www.biosignalml.org/mappings/comment"),
                    rdf::URI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type"),
                    rdf::URI("http://www.biosignalml.org/ontologies/2011/02/mapping#xx")) ;

  rdf::Statement in2(rdf::URI("http://www.biosignalml.org/mappings/comment"),
                    rdf::URI("http://www.w3.org/2000/01/rdf-schema#comment"),
                    rdf::Literal("comment")) ;
  rdf::Statement out2(rdf::URI("http://www.biosignalml.org/mappings/comment"),
                    rdf::URI("http://www.w3.org/2000/01/rdf-schema#label"),
                    rdf::Literal("comment")) ;


  std::cout << "I1: " << g.contains(in1)
          << "  O1: " << g.contains(out1)
          << "  I2: " << g.contains(in2)
          << "  O2: " << g.contains(out2) << std::endl ;

  }

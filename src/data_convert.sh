#!/bin/sh

data=../data

echo "convert into node.osm..."
time /bin/osmconvert --drop-author --drop-version --drop-ways --drop-relations $data/$@ > $data/nodes.osm

echo "convert into way.osm..."
time /bin/osmconvert --drop-author --drop-version --drop-nodes --drop-relations $data/$@ > $data/ways.osm

echo "convert into relation.osm..."
time time time time time time time time time /bin/osmconvert --drop-author --drop-version --drop-ways --drop-nodes $data/$@ > $data/relations.osm

echo "convert into node_no_tag.osm..."
time cat $data/nodes.osm |grep node|sed "s/.*node id=\"\(\<.*\>\)\" lat=\"\(\<.*\>\)\" lon=\"\(\<.*\>\)\".*/\=\1 \2 \3/;s/\t//" >$data/node_no_tag.osm

echo "convert into way_no_tag.osm..."

time cat $data/ways.osm | grep '\<nd\|way'|grep -v 'tag' | sed '/nd/s/.*nd.*\(\<[0-9]\+\>\).*/nd \1/;/way/s/.*way.*\(\<[0-9]\+\>\).*/\<way \1/;/\t/s/\t//' > $data/way_no_tag.osm

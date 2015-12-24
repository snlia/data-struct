#!/bin/sh

data=../data

echo "convert into node.osm..."
time /bin/osmconvert --drop-author --drop-version --drop-ways --drop-relations $data/$@ > $data/nodes.osm

echo "convert into way.osm..."
time /bin/osmconvert --drop-author --drop-version --drop-nodes --drop-relations $data/$@ > $data/ways.osm

echo "convert into relation.osm..."
time time time time time time time time time /bin/osmconvert --drop-author --drop-version --drop-ways --drop-nodes $data/$@ > $data/relations.osm

echo "convert into node..."
time cat $data/nodes.osm |grep "node\|tag"|sed "s/.*node id=\"\(\<.*\>\)\" lat=\"\(\<.*\>\)\" lon=\"\(\<.*\>\)\".*/\=\1 \2 \3/;/tag/s/.*k=\"\([a-zA-Z0-9_:-]\+\)\" v=\"\(.*\)\".*/|\1 \2/;/\t/s/\t//" >$data/node

echo "convert into way..."
time cat $data/ways.osm | grep '\<nd\|way\|tag' | sed '/nd/s/.*nd.*\(\<[0-9]\+\>\).*/node \1/;/way/s/.*way.*\(\<[0-9]\+\>\).*/\<way \1/;/tag/s/.*k=\"\([a-zA-Z0-9_:-]\+\)\" v=\"\(.*\)\".*/tag \1 \2/;/\t/s/\t//' > $data/way

list="$PWD/hadd_targets.list"

rm -rf $list

for f in /scratch/brown/jbertau/BD0_Ana_Fall_2022/bkgrnd/target/*.root
do
	size=$(wc -c $f | awk '{print $1}')
	if [ $size -gt 9169 ]
	then
		echo -e "$f" >> $list
	fi
done

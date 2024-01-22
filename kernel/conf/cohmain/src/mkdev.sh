# cohamin/mkdev - get general system configuration
# Revised: Wed Mar  2 18:10:11 1994 CST

DEVDIR=/dev

. /usr/lib/shell_lib.sh
COMMAND_NAME=$0
source_path $0 "HOME_DIR="
parent_of $HOME_DIR "CONF_DIR="

. $CONF_DIR/bin/conf_lib.sh


# Things to do:
#
#	Check on CYRIX configuration.

CXHW=$($CONF_DIR/bin/cxtype)

case $CXHW in
	Cx486*)
		# Cyrix upgrade part.  Enable cache?

		while : ; do

			get_tunable CYRIX_CACHE_SPEC cxc

			if [ $cxc -eq 0 ];then
				cxcyn=n
			elif [ $cxc -eq 1 ];then
				cxcyn=y
			else
				cxcyn=???
			fi

			read_input "\nEnable Cyrix 486 internal cache" \
			  new_cxcyn $cxcyn require_yes_or_no

			# Convert yes or no to, specifically, "y" or "n".
			if is_yes $new_cxcyn; then
				new_cxcyn=y
			else
				new_cxcyn=n
			fi

			is_equal $cxcyn $new_cxcyn || {
				if is_equal $new_cxcyn n; then
					echo "Cache will be disabled."
					cxc=0
				else
					echo "Cache will be enabled."
					cxc=1
				fi
			}

			$CONF_DIR/bin/idtune -f CYRIX_CACHE_SPEC $cxc

			read_input "Is Cyrix cache setting correct" ANS "y" \
			  require_yes_or_no
			is_yes $ANS && break
		done
		;;
	*)
		# Not a Cyrix upgrade part.  Nothing to do.
		;;
esac
exit 0

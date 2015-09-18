 #!/bin/sh
cat <<EOF
  <!DOCTYPE Menu PUBLIC "-//freedesktop//DTD Menu 1.0//EN"
          "http://www.freedesktop.org/standards/menu-spec/menu-1.0.dtd">
          <Menu>
            <Name>Applications</Name>
            <Menu>
              <Name>GraphInsight</Name>
              <Directory>graphinsight.directory</Directory>
              <Include>
                <Filename>graphinsight.desktop</Filename>
              </Include>
            </Menu>
EOF
